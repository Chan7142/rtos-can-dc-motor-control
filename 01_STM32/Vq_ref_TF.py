import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

# ==========================================
# 1. 사용자 설정 변수 (실제 환경에 맞게 수정하세요)
# ==========================================
FILE_NAME = 'Vq_TF.txt'        # CoolTerm으로 저장한 파일명
V_Q_REF_STEP = 5.0            # 인가한 Vq_ref 스텝 입력의 크기 (예: 5V, 5A 등)
TIME_DELAY = 0.0              # 데이터 기록 시작 후 스텝이 인가되기까지의 지연 시간(초)

# ==========================================
# 2. 1차 시스템 스텝 응답 함수 정의
# ==========================================
# 수식: y(t) = K * U * (1 - exp(-(t - delay)/tau))
def first_order_step(t, K, tau):
    # 시간 지연(delay) 이전의 응답은 0으로 처리
    response = np.zeros_like(t)
    mask = t >= TIME_DELAY
    response[mask] = K * V_Q_REF_STEP * (1 - np.exp(-(t[mask] - TIME_DELAY) / tau))
    return response

# ==========================================
# 3. 데이터 로드 및 전처리
# ==========================================
try:
    # 쉼표(,) 기준으로 데이터 로드
    data = np.loadtxt(FILE_NAME, delimiter=',')
    time = data[:, 0]
    speed_rad = data[:, 1]
    
    # 시간 축을 0부터 시작하도록 보정 (필요한 경우)
    time = time - time[0]

except Exception as e:
    print(f"데이터 로드 실패: {e}")
    print("파일 포맷이 '시간, 속도' 형태인지 확인해주세요.")
    exit()

# ==========================================
# 4. Curve Fitting을 통한 파라미터(K, tau) 추정
# ==========================================
# p0는 최적화를 위한 초기 추정값입니다. [K_초기값, tau_초기값]
# 피팅이 잘 안 된다면 이 값을 예상되는 근사치로 변경해주세요.
initial_guess = [10.0, 0.1] 

try:
    popt, pcov = curve_fit(first_order_step, time, speed_rad, p0=initial_guess)
    K_est, tau_est = popt
    
    # ==========================================
    # 5. 결과 출력
    # ==========================================
    print("-" * 40)
    print("✅ 시스템 식별 결과 (1차 지연 모델)")
    print("-" * 40)
    print(f"DC Gain (K)     : {K_est:.4f} [(rad/s) / Vq_ref]")
    print(f"Time Constant (τ): {tau_est:.4f} [s]")
    print("-" * 40)
    print(f"전달함수 G(s)   = {K_est:.4f} / ({tau_est:.4f}s + 1)")
    print("-" * 40)

    # ==========================================
    # 6. 결과 시각화 (검증용)
    # ==========================================
    plt.figure(figsize=(10, 6))
    plt.plot(time, speed_rad, 'b-', label='Measured Data (CoolTerm)', alpha=0.7)
    plt.plot(time, first_order_step(time, *popt), 'r--', label='Fitted Transfer Function', linewidth=2)
    
    plt.axvline(x=TIME_DELAY, color='k', linestyle=':', label='Step Applied')
    plt.xlabel('Time [s]')
    plt.ylabel('Speed [rad/s]')
    plt.title('Vq_ref Step Response & System Identification')
    plt.legend()
    plt.grid(True)
    plt.show()

except RuntimeError:
    print("최적의 파라미터를 찾지 못했습니다. 데이터의 노이즈가 너무 심하거나 초기 추정값(initial_guess) 조정이 필요합니다.")