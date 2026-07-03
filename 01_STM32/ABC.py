import pandas as pd
import matplotlib.pyplot as plt
import os

# =================================================================
# 1. 파일 설정 (텍스트 파일명이 다르면 이 부분을 수정하세요)
# =================================================================
current_dir = os.path.dirname(os.path.abspath(__file__))
file_name = 'cABC.txt' 

# 폴더 경로와 파일 이름을 합쳐서 완벽한 전체 경로를 만듭니다.
file_path = os.path.join(current_dir, file_name)

if not os.path.exists(file_path):
    print(f"[오류] '{file_path}' 파일을 찾을 수 없습니다. 파일이 스크립트와 같은 폴더에 있는지 확인해 주세요.")
else:
    try:
        # 데이터 로드 (콤마 분할 및 공백 제거)
        df = pd.read_csv(file_path, names=['time', 'I_a', 'I_b', 'I_c'], header=None, skipinitialspace=True)

        # =================================================================
        # 2. 그래프 그리기
        # =================================================================
        plt.figure(figsize=(14, 6))

        # A상 전류 (주황색 계열)
        plt.plot(df['time'], df['I_a'], label='Phase A (Ia)', color='#ff7f0e', alpha=0.8, linewidth=1.2)
        
        # B상 전류 (초록색 계열)
        plt.plot(df['time'], df['I_b'], label='Phase B (Ib)', color='#2ca02c', alpha=0.8, linewidth=1.2)
        
        # C상 전류 (빨간색 계열)
        plt.plot(df['time'], df['I_c'], label='Phase C (Ic)', color='#d62728', alpha=0.8, linewidth=1.2)

        # 0A 가이드라인 선 추가 (중심축 확인용)
        plt.axhline(y=0.0, color='black', linestyle=':', alpha=0.5, linewidth=1)

        # =================================================================
        # 3. 그래프 스타일링
        # =================================================================
        plt.title('BLDC 3-Phase Current Analysis (Ia / Ib / Ic)', fontsize=14, fontweight='bold', pad=15)
        plt.xlabel('Time (seconds)', fontsize=12, labelpad=10)
        plt.ylabel('Current (A)', fontsize=12, labelpad=10)
        
        plt.grid(True, linestyle='--', alpha=0.5)
        plt.legend(fontsize=11, loc='upper right')
        
        plt.tight_layout()
        plt.show()

    except Exception as e:
        print(f"[오류] 데이터를 파싱하는 중 문제가 발생했습니다: {e}")