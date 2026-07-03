import os
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

# 1. 파일 이름 설정 (CoolTerm에서 저장한 파일 이름으로 변경하세요)
file_name = 'theta_data.txt' 

# 현재 파이썬 파일이 있는 폴더의 절대 경로를 찾아 파일 경로 완성
current_dir = os.path.dirname(os.path.abspath(__file__))
file_path = os.path.join(current_dir, file_name)

print(f"읽어올 파일 경로: {file_path}")

try:
    print("데이터를 불러오고 있습니다...")
    
    # 2. 데이터 불러오기 
    # 출력 순서: time, rtU.ref, theta_rad
    df = pd.read_csv(file_path, header=None, names=['Time', 'Target_Angle', 'Actual_Angle'], on_bad_lines='skip')

    # 3. 데이터 정제 (문자열 제거 및 결측치 삭제)
    df = df.apply(pd.to_numeric, errors='coerce').dropna()

    if df.empty:
        print("그래프를 그릴 유효한 숫자 데이터가 없습니다. txt 파일 내용을 확인해주세요.")
    else:
        # 4. 그래프 그리기 세팅
        plt.figure(figsize=(12, 6))
        
        # 목표 각도 (빨간색 점선)
        plt.plot(df['Time'], df['Target_Angle'], label='Target Angle (rtU.ref)', color='red', linestyle='--', linewidth=2.0)
        
        # 실제 각도 (파란색 실선)
        plt.plot(df['Time'], df['Actual_Angle'], label='Actual Angle (theta_rad)', color='blue', linewidth=1.5)
        
        # 그래프 디자인 요소
        plt.title('Motor Position Tracking (Target vs Actual)', fontsize=16)
        plt.xlabel('Time (s)', fontsize=12)
        plt.ylabel('Angle (rad)', fontsize=12) # 라디안 단위
        
        plt.legend(fontsize=12, loc='upper right')
        plt.grid(True, linestyle=':', alpha=0.7)
        plt.tight_layout()
        
        # 5. 화면에 출력
        print("그래프를 띄웁니다!")
        plt.show()

except FileNotFoundError:
    print(f"\n❌ 에러: [{file_name}] 파일을 찾을 수 없습니다.")
    print("파이썬 스크립트와 txt 파일이 같은 폴더에 있는지 다시 한 번 확인해주세요.")
except Exception as e:
    print(f"\n❌ 알 수 없는 오류가 발생했습니다: {e}")