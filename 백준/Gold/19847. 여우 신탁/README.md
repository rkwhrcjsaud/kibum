# [Gold II] 여우 신탁 - 19847 

[문제 링크](https://www.acmicpc.net/problem/19847) 

### 성능 요약

메모리: 5928 KB, 시간: 40 ms

### 분류

다이나믹 프로그래밍, 수학, 확률론

### 제출 일자

2024년 5월 28일 18:14:25

### 문제 설명

<p><span style="font-style: italic;">“여우신님, 여우신님, 번호 하나만 내려 주세요…”</span></p>

<p>누구나 1 이상 45 이하의 정수 여섯 개를 잘 골라서 인생이 달라지거나, 혹은 1 이상 10,000 이하의 정수 하나를 잘 골라서 <span style="font-weight: bold; color: #009874;">맞았습니다!!</span>를 받는 헛된 꿈을 꾼다. 이렇듯 일상 생활에서 신기가 담긴 수가 필요한 상황은 얼마든지 일어난다. 이는 여우 마을의 여우들에게도 마찬가지다. 다만 여우 마을과 현실의 차이점은, 여우 마을에서는 여우신에게 부탁을 드리면 실제로 여우신께서 신탁으로 수를 하나 내려 주신다는 점이다.</p>

<p>여우 마을의 여우들은 수를 셀 때 0부터 세기 때문에, <span style="font-style: italic;">X</span>개의 수 중 하나가 필요할 때는 여우신에게 “0 이상 <span style="font-style: italic;">X</span> <strong>미만</strong>의 수를 하나 내려 주세요”와 같이 부탁을 드린다. 그러면 여우신은 0 이상 <span style="font-style: italic;">X</span> − 1 이하의 정수 하나를 <strong>균일한</strong> 확률로 골라서 신탁으로 내려 준다.</p>

<p>그러나 너무 많은 여우들이 여우신을 찾게 되자, 여우신은 매번 새로운 수를 고르기가 귀찮아졌다. 그래서 여우신은 여우들이 올린 부탁을 여러 개 모아서 한꺼번에 처리하기로 했다. 첫 번째 여우에게는 제대로 수를 골라서 내려 주고, 그 다음부터는 바로 전에 내려 줬던 수를 새로 부탁받은 값으로 나눈 <strong>나머지</strong>를 내려 주기로 한 것이다.</p>

<p>예를 들어 여우 세 마리가 차례대로 10개의 수 중 하나, 3개의 수 중 하나, 5개의 수 중 하나를 필요로 할 경우 여우신은 다음과 같은 방법으로 신탁을 내린다.</p>

<ol>
	<li>0 이상 9 이하의 정수를 균일한 확률로 하나 골라서 첫 번째 여우에게 내려 준다.</li>
	<li>첫 번째 여우에게 내려 준 수를 3으로 나눈 나머지를 두 번째 여우에게 내려 준다.</li>
	<li>두 번째 여우에게 내려 준 수를 5로 나눈 나머지를 마지막 여우에게 내려 준다.</li>
</ol>

<p>물론 신탁을 받는 여우들은 눈치채지 못하겠지만, 이렇게 내려 주는 신탁은 공정한 신탁이 아닐 수 있다. 여우신이 반성하고 다시 제대로 신탁을 내릴 수 있도록, 마지막 여우가 받게 되는 수의 분포를 계산해서 보여 주자.</p>

### 입력 

 <p>첫 줄에 신탁을 요청한 여우의 수를 의미하는 정수 <span style="font-style: italic;">N</span>이 주어진다.</p>

<p>다음 줄에는 <span style="font-style: italic;">N</span>개의 정수 <span style="font-style: italic;">x</span><sub>1</sub>, <span style="font-style: italic;">x</span><sub>2</sub>, …, <span style="font-style: italic;">x</span><sub><span style="font-style: italic;">N</span></sub>이 공백을 사이에 두고 차례대로 주어진다. <span style="font-style: italic;">x</span><sub><span style="font-style: italic;">i</span></sub>는 <span style="font-style: italic;">i</span>번째 여우가 <span style="font-style: italic;">x</span><sub><span style="font-style: italic;">i</span></sub>개의 수 중 하나를 필요로 함을 의미한다.</p>

### 출력 

 <p>마지막 여우가 받게 되는 수의 기댓값을 출력한다. 절대 또는 상대 오차가 10<sup>−9</sup> 이하면 정답으로 처리된다.</p>

