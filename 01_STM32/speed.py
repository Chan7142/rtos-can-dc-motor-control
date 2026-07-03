import os
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from scipy.optimize import curve_fit

# ==========================================
# 1. 파일 경로 설정 (현재 스크립트 기준 절대 경로)
# ==========================================
current_dir = os.path.dirname(os.path.abspath(__file__))
file_name = 'Vq_TF.txt' 
file_path = os.path.join(current_dir, file_name)

# ==========================================
# 2. 사용자 설정 변수 (실제 실험에 맞게 수정하세요)
# ==========================================
V_Q_REF_STEP = 4.0            # 인가한 Vq_ref 스텝 입력의 크기 (예: 5V)
TIME_DELAY = 0.0              # 데이터 시작 후 스텝 입력이 들어간 시점(초)

# ==========================================
# 3. 1차 시스템 스텝 응답 함수 정의
# ==========================================
# 수식: y(t) = K * U * (1 - exp(-(t - delay)/tau))
def first_order_step(t, K, tau):
    response = np.zeros_like(t)
    mask = t >= TIME_DELAY
    response[mask] = K * V_Q_REF_STEP * (1 - np.exp(-(t[mask] - TIME_DELAY) / tau))
    return response

# ==========================================
# 4. 데이터 로드 및 전처리
# ==========================================
print(f"데이터 파일을 불러오는 중: {file_path}")

try:
    # CoolTerm 메모장 데이터는 빈 줄이나 공백이 있을 수 있으므로 pandas로 안전하게 로드
    # 쉼표(,) 분리, 헤더(컬럼명)가 없다고 지정
    df = pd.read_csv(file_path, delimiter=',', header=None).dropna()
    
    # numpy 배열로 변환
    time = df[0].to_numpy()
    speed_rad = df[1].to_numpy()
    
    # 시간 축을 0초부터 시작하도록 보정
    time = time - time[0]

except Exception as e:
    print(f"\n❌ 데이터 로드 실패: {e}")
    print("Tip: 파일이 스크립트와 동일한 폴더에 있는지, '시간, 속도' 형태로 저장되었는지 확인해주세요.")
    exit()

# ==========================================
# 5. Curve Fitting을 통한 시스템 식별
# ==========================================
# [K_초기값, tau_초기값] -> 모터 스펙에 맞춰 근사치를 넣어주면 정확도가 올라갑니다.
initial_guess = [10.0, 0.1] 

try:
    popt, pcov = curve_fit(first_order_step, time, speed_rad, p0=initial_guess)
    K_est, tau_est = popt
    
    # ==========================================
    # 6. 결과 출력
    # ==========================================
    print("\n" + "="*40)
    print("✅ BLDC 모터 시스템 식별 완료 (rad/s 단위)")
    print("="*40)
    print(f"▶ 직류 이득 (DC Gain, K) : {K_est:.4f} [(rad/s) / V]")
    print(f"▶ 시정수 (Time Const, τ) : {tau_est:.4f} [초]")
    print("-"*40)
    print(f"▶ 추출된 전달함수 G(s)   = {K_est:.4f} / ({tau_est:.4f}s + 1)")
    print("="*40)

    # ==========================================
    # 7. 결과 시각화 (측정치 vs 피팅 결과 비교)
    # ==========================================
    plt.figure(figsize=(10, 6))
    plt.plot(time, speed_rad, 'b-', label='Measured Data (CoolTerm)', alpha=0.6)
    plt.plot(time, first_order_step(time, *popt), 'r--', label='Identified 1st-order Model', linewidth=2.5)
    
    if TIME_DELAY > 0:
        plt.axvline(x=TIME_DELAY, color='k', linestyle=':', label='Step Input Applied')
        
    plt.xlabel('Time [s]')
    plt.ylabel('Speed [rad/s]')
    plt.title('BLDC Motor Vq_ref Step Response & System Identification')
    plt.legend()
    plt.grid(True, linestyle='--', alpha=0.7)
    plt.show()

except RuntimeError:
    print("\n❌ 최적의 파라미터를 찾지 못했습니다.")
    print("데이터의 노이즈가 너무 심하거나, TIME_DELAY 및 V_Q_REF_STEP 설정이 올바른지 확인하세요.")