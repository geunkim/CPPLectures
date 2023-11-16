# STL 알고리즘

일반적으로 데이터에 대한 탐색(searching), 정렬(sorting), 계수 (counting)과 같은 알고리즘은 프로그램에서 널리 사용된다. 
STL에서도 컨테이너에 저장된 데이터에 대한 문제를 해결하기 위해 템플릿 함수를 제공한다.  

## 컨테이너 공통 멤버 함수

아래의 멤버 함수들은 모든 컨테이너가 제공하는 것으로 컨테이너의 종류에 관계 없이 사용된다. 

|함수(function) | 설명(description) |
|:----:|:----:|
| Container() | 기본 생성자 |
| Container(size) | 크기가 size인 컨테이너 생성 |
| Container(size, value) | 크기가 size이고 모든 데이터 값이 value인 컨테이너 생성 |
| Container(iterator, iterator) | 다른 컨테이너의 지정 범위의 데이터로 컨테이너 생성 |
| begin() | 첫 번쨰 데이터의 반복자 위치 |
| end() | 반복자가 마지막 데이터 위치를 지난 위치 |
| clear() | 컨테이너 내 모든 데이터를 삭제 | 
| empty() | 컨테이너가 비어 있는지 감사 |
| erase(iterator) | 컨테이너의 반복자가 위치하는 곳의 데이터 삭제 | 
| erase(iterator, iterator) | 컨테이너의 지정된 범위를 삭제 |
| front() | 컨테이너의 첫 번째 데이터 반환 |
| insert(iterator, value) | 컨테이너에서 반복자가 위치한 다음 위치에 value를 삽입 |
| pop_back() | 컨테이너의 마지막 데이터 삭제 |
| push_back(value) | 컨테이너의 끝에 데이터 추가 |
| rbegin() | 컨테이너의 마지막을 나타내는 역반복자 |
| rend() | 역반복자가 컨테이너의 첫 데이터 위치를 지난 위치|
| size() | 컨테어니 크기 |
| operator=(Container) | 대입 연산자 중복 정의 |

## 알고리즘 분류

STL 알고리즘은 컨테이너에 저장된 데이터 값의 내용과 순서를 변경하지 않는 알고리즘(불변경 알고리즘)과 컨테이너에 저장된 데이터가 변경될 수 있는
알고리즘(변경 알고리즘)으로 분류할 수 있다. 

## 불변경 알고리즘
| 분류 | 알고리즘 | 설명 |
|:---:|:---|:---|
| 계수 | size_t count(iterator start, iterator end, const TYPE& val) | 컨테이너의 [start, end)에서 주어진 값과 일치하는 데이터의 개수를 반환 |
| 계수 | size_t count_if(iterator start, iterator end, UnaryPred p) | 컨테이너의 [start, end)에서 p()가 true가 되는 데이터의 개수를 반환 |
| 탐색 | iterator search(iterator start1, iterator end1, iterator start2, iterator end2); | 컨테이너 [start1, end1)에서 [start2, end2)요소가 있는지를 찾아서 첫 번째 요소의 반복자 반환 |
| 탐색 | iterator search_n(iterator start, iterator end, size_t num, const TYPE& val); | 컨테이너의 [start, end) 에서 num 번 째 val 값의 요소의 반복자 반환 |
| 탐색 | iterator find(iterator start, iterator end, const TYPE& val); | 컨테이너의 [star, end)에서 val 값을 찾아 val 값을 포인팅하는 반복자를 반환 |
| 탐색 | iterator find_if(iterator start, iterator end, UnPred up); |  컨테이너의 [star, end)에서 up()이 true를 반환하는 첫번 째 요소에 대한 반복자를 반환 |
| 탐색 | iterator find_end(iterator start, iterator end, iterator seq_start, iterator seq_end) | 컨테이너의 [start, end)에서 [seq_start, seq_end)의 시퀀스를 찾아 마지막에 나타나는 시퀀스의 첫번 쨰 요소의 반환자를 반환 |
| 탐색 | iterator find_first_of(iterator start, iterator end, iterator find_start, iterator find_end); | 컨테이너의 [first_start, first_end)의 요소 중 [start, end)의 데이터가 처음 나타나는 것의 반복자를 반환 |
| 탐색 | bool binary_search(iterator start, iterator end, const TYPE& val) | 컨테이너에서 [start, end)에서 주어진 값이 있는지 탐색 | 
| 탐색 | iterator max_element(iterator start, iterator end) | 컨테이너의 [start, end)에서 최대값이 저장된 위치 반환 |
| 탐색 | iterator min_element(iterator start, iterator end) | 컨테이너의 [start, end)에서 최소값이 저장된 위치 반환 |
| 정렬 | void sort(iterator start, iterator end) | 컨테이너의 [start, end)에서 값을 정렬 |
| 정렬 | void reverse(first_iterator, last_iterator) | 컨테이너의 [start, end)의 데이터 순서를 반전 |



