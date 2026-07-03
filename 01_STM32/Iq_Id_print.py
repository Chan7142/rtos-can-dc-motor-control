import os
import pandas as pd
import matplotlib.pyplot as plt

# =================================================================
# 1. 파일 설정 (텍스트 파일명이 다르면 이 부분을 수정하세요)
# =================================================================
current_dir = os.path.dirname(os.path.abspath(__file__))
file_name = 'BLDC_speed.txt' 

# 폴더 경로와 파일 이름을 합쳐서 완벽한 전체 경로를 만듭니다.
file_path = os.path.join(current_dir, file_name)

try:
    # 콤마(,) 분할 및 앞뒤 공백 제거하여 데이터프레임으로 로드
    # header=None은 파일에 컬럼 이름 행이 없을 때 설정합니다.
    df = pd.read_csv(file_path, names=['time', 'Id', 'Iq'], header=None, skipinitialspace=True)

    # =================================================================
    # 2. 그래프 그리기
    # =================================================================
    plt.figure(figsize=(12, 6))

    # Id 전류 그래프 (파란색)
    plt.plot(df['time'], df['Id'], label='Id (Direct Current)', color='#1f77b4', alpha=0.8, linewidth=1.5)

    # Iq 전류 그래프 (빨간색)
    plt.plot(df['time'], df['Iq'], label='Iq (Quadrature Current)', color='#d62728', alpha=0.8, linewidth=1.5)

    # =================================================================
    # 3. 그래프 스타일링 및 꾸미기
    # =================================================================
    plt.title('BLDC FOC Current Analysis (Id / Iq)', fontsize=14, fontweight='bold', pad=15)
    plt.xlabel('Time (seconds)', fontsize=12, labelpad=10)
    plt.ylabel('Current (A)', fontsize=12, labelpad=10)
    
    # 격자(Grid) 추가
    plt.grid(True, linestyle='--', alpha=0.5)
    
    # 범례(Legend) 추가
    plt.legend(fontsize=11, loc='upper right')

    # 그래프 여백 최적화 및 출력
    plt.tight_layout()
    plt.show()

except FileNotFoundError:
    print(f"[오류] '{file_path}' 파일을 찾을 수 없습니다. 파이썬 스크립트와 같은 폴더에 있는지 확인해 주세요.")
except Exception as e:
    print(f"[오류] 데이터를 읽는 중 문제가 발생했습니다: {e}")