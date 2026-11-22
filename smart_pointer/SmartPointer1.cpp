/*
 * 포인터와, 참조는 완전히 동일하게 동작한다.
 */

void foo(int a) {
    int b = a+1;
}

void foop(int *p) {
    int b = *p + 1;
}

void foof(int &ref) {
    int b = ref + 1;
}

int main() {
    int a = 10;
    return 0;
}
//스택구조로 그렸다.
/*값의 복사
 * a = 10, b = 11
 *--------
 * a = 10
 */

/* 포인터와 참조는 정확히 같은 방식으로 동작한다.
 * p = &a , b = 11
 *--------
 * a = 10
 */