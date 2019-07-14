
int main()
{
    volatile int vflag = 100;
    int flag = 300;

    while (vflag == 100) {
        1 + 1;
    }

    while (flag == 300) {
        2 + 2;
    }

    return 0;
}