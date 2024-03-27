# [Gold IV] 두 개의 문 - 17453 

[문제 링크](https://www.acmicpc.net/problem/17453) 

### 성능 요약

메모리: 15860 KB, 시간: 28 ms

### 분류

비트마스킹, 브루트포스 알고리즘

### 제출 일자

2024년 3월 27일 19:00:05

### 문제 설명

<p>도도는 시공의 폭풍으로 빨려 들어간 에아를 찾으러 나섰습니다. 에아가 지금으로부터 미래로 (-<span style="font-style: italic;">n</span>)년과 <span style="font-style: italic;">n</span>년 사이에 있다는 정보만 알고서 타임머신을 찾아 나선 도도는, 검은 마법사로부터 신기한 문을 알아냈습니다.</p>

<p>이 문은 앞면과 뒷면이 있으며, 앞면이 뒷면보다 항상 1년 미래입니다. 즉, 문을 앞에서 뒤로 들어가면 1년 과거로 갈 수 있고, 뒤에서 앞으로 들어가면 1년 미래로 갈 수 있습니다.</p>

<p>악마 같은 검은 마법사는 이 문을 그냥 줄 수는 없다면서, <span style="font-style: italic;">n</span>개의 문을 이어붙인 통로를 주겠다고 했습니다. 도도는 오랜 연구 끝에 특정 문의 조합을 180도 돌릴 수 있는 <span style="font-style: italic;">m</span>개의 스위치를 설치했습니다. 이제 이 스위치를 사용하여 에아를 구하러 갑시다!</p>

### 입력 

 <p>첫째 줄에 <span style="font-style: italic;">n</span>(1 ≤ <span style="font-style: italic;">n</span> ≤ 100)과 <span style="font-style: italic;">m</span>(1 ≤ <span style="font-style: italic;">m</span> ≤ 20)이 주어집니다.</p>

<p>둘째 줄에 길이 <span style="font-style: italic;">n</span>의 <code>0</code>과 <code>1</code>로만 구성된 문자열이 주어집니다. 모든 1 ≤ <span style="font-style: italic;">j</span> ≤ <span style="font-style: italic;">n</span>에 대해, 이 문자열의 <span style="font-style: italic;">j</span>번째 문자는 <span style="font-style: italic;">j</span>번째 문의 초기 상태를 나타내며, <code>0</code>이라면 문의 앞면, <code>1</code>이라면 문의 뒷면이 도도를 향하고 있음을 나타냅니다.</p>

<p>셋째 줄부터 (<span style="font-style: italic;">m</span>+2)번째 줄까지 길이 <span style="font-style: italic;">n</span>의 <code>0</code>과 <code>1</code>로만 구성된 문자열 <span style="font-style: italic;">m</span>개가 주어집니다. 모든 1 ≤ <span style="font-style: italic;">i</span> ≤ <span style="font-style: italic;">m</span>, 1 ≤ <span style="font-style: italic;">j</span> ≤ <span style="font-style: italic;">n</span>에 대해 (<span style="font-style: italic;">i</span>+2)번째 줄의 <span style="font-style: italic;">j</span>번째 문자는 <span style="font-style: italic;">i</span>번 스위치가 <span style="font-style: italic;">j</span>번 문을 180도 돌리는지 여부를 나타내며, <code>0</code>이라면 돌리지 않음을, <code>1</code>이라면 돌림을 의미합니다.</p>

### 출력 

 <p>총 (2<span style="font-style: italic;">n</span>+1)개의 줄을 출력합니다. 모든 -<span style="font-style: italic;">n</span> ≤ <span style="font-style: italic;">i</span> ≤ <span style="font-style: italic;">n</span>에 대해, (<span style="font-style: italic;">i</span>+<span style="font-style: italic;">n</span>+1)번째 줄에는 미래로 <span style="font-style: italic;">i</span>년을 가려고 할 때에 해당하는 답을 출력합니다.</p>

<p>각 줄에는, 정답이 존재한다면 눌러야 하는 스위치의 개수 <span style="font-style: italic;">k</span>(0 ≤ <span style="font-style: italic;">k</span> ≤ <span style="font-style: italic;">m</span>)와 스위치 번호를 공백을 사이에 두고 출력합니다. 정답이 존재하지 않으면 <code>-1</code>을 출력합니다.</p>

<p>눌러야 하는 스위치의 조합이 여러 가지라면 아무거나 하나를 출력합니다.</p>

