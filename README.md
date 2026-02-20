*This project has been created as part of the 42 curriculum by hwalee.*

# ft_printf

## Description
목표 : 나만의 printf 만들기
구현하는 과정에서 가변인자(`stdarg.h`)개념을 배움

## Instructions
### 1. 빌드
```bash
make
```
- 결과물: `ft_printf.a`

### 2. 정리
```bash
make clean
make fclean
make re
```

### 3. 사용 방법
헤더를 포함하고, 정적 라이브러리를 링크해 사용합니다.

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("char=%c, str=%s, dec=%d, hex=%x, ptr=%p\n", 'A', "hello", 42, 255, "hello");
    return (0);
}
```

예시 컴파일:
```bash
cc -Wall -Wextra -Werror your_main.c ft_printf.a -I. -I./libft -o test_printf
./test_printf
```

## Algorithm Selection and Justification
이 프로젝트에서 선택한 알고리즘은 크게 `파싱 단계`와 `출력 단계`의 분리입니다.

### 1. 파싱 단계 (`ft_printf.c`)
- 입력 문자열을 왼쪽에서 오른쪽으로 순회합니다.
- 일반 문자는 연속 구간 단위로 `write`로 그대로 출력합니다.
- `%`를 만나면 `format` 구조체를 초기화하고, `fill_format`에서 다음 항목을 순차적으로 읽습니다.
- 플래그 집합(`#`, ` `, `+`, `-`, `0`)
- 폭(`width`)
- 정밀도(`precision`)
- 타입(`cspdiuxX`)
- 최종적으로 `print_format`에서 타입별 함수(`print_type_*`)로 분기합니다.

### 2. 출력 단계 (`print_type_*.c`)
- 각 타입 함수는 `va_arg`로 해당 타입 값을 꺼내 출력합니다.
- `%u`, `%x`, `%X`, `%p`는 재귀 기반 숫자 출력으로 자릿수를 상위 자리부터 출력합니다.
- `%p`는 `NULL`이면 `(nil)`, 아니면 `0x` 접두어 + 16진수 주소를 출력합니다.

### 3. 이 알고리즘을 선택한 이유
- 확장 용이성: 현재는 단순 출력이지만, 이후 플래그/폭/정밀도 반영 로직을 각 타입 함수에 확장하기 쉽습니다.
- 메모리 효율: 숫자 출력에 동적 할당 없이 재귀와 `write`를 사용해 O(1) 추가 메모리(재귀 스택 제외)로 동작합니다.

### 4. 복잡도
- 시간 복잡도: `O(n + k)`
- `n`: 포맷 문자열 길이
- `k`: 출력되는 숫자 자릿수 합
- 공간 복잡도: `O(1)` (재귀 호출 스택 제외)

## Resources
### 참고 자료
- ISO C 관련 문서(가변 인자, 정수 출력 규칙)
- `ft_printf` 과제pdf

### AI 사용 내역
- 사용 도구: OpenAI Codex
- README 초안 작성 및 요구사항 누락 점검
