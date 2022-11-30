#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

double f(double x);
double halfed(double x1, double x2, int n_count, int N, const double eps);
double chord(double x1, double x2, int n_count, int N, const double eps);

int main() {

    SetConsoleCP (65001);
    SetConsoleOutputCP (65001);

    int N, method, n_count=0;
    double x1, x2;
    const double eps=0.0001;
    double result;
    clock_t time, t_time;

    printf("\t Виберіть метод розв'язування:");
    printf("\n\t Для методу половинення інтервалів натисніть 1");
    printf("\n\t Для методу хорд натисніть 2\n");
    scanf("%u", &method);
    while (method!=1&&method!=2) {
        printf("\t Введені неправильні дані, будь ласка повторіть!\n");
        printf("\t Виберіть метод розв'язування:");
        printf("\n\t Для методу половинення інтервалів натисніть 1");
        printf("\n\t Для методу хорд натисніть 2\n");
        scanf("%u", &method);
    }

    printf("Будь ласка введіть наступні дані:");
    do {
        printf("\n\tX1: ");
        scanf("%lf", &x1);
        printf("\n\tX2: ");
        scanf("%lf", &x2);
    } while (f(x1)*f(x2) <= 0);

    printf("\n\tN: ");
    scanf("%u", &N);

    system("cls");

    switch(method) {
        case 1:
        {
            result = halfed(x1,x2, n_count, N, eps);
        }
            break;

        case 2:
        {
            result = chord(x1, x2, n_count, N, eps);
        }
            break;

    }
    time=clock()-time;
    t_time = ((double)time)/CLOCKS_PER_SEC;
    printf ("Витрачено часу: %.2lf секунд\n", t_time);
    return 0;
}

double halfed(double x1, double x2, int n_count, int N, const double eps) {

    double xi;
    unsigned int choice, const_n;
    const_n=N;

    do {

        n_count++;
        xi=(x1+x2)/2;
        if(f(xi)*f(x1)>0) {
            x1=xi;
        }
        else {
            x2=xi;
        }

        if (n_count%N==0) {

            printf ("Кількість виповнених ітерацій: %u", n_count);
            printf ("\n Поточний Х: %.3lf", xi);
            printf ("\n Поточна f(x)= %.3lf", f(xi));
            printf ("\n\n Виберіть що робити далі");

            printf ("\n\t 1 Продовжити з такою самою кількістю ітерацій");
            printf ("\n\t 2 Продовжити поки корінь не буде знайдено");
            printf ("\n\t 3 Вийти і показати поточний результат");

            scanf ("%u", &choice);
            printf ("==============================================================\n");

            while (choice!=1&&choice!=2&&choice!=3) {
                scanf("%u", &choice);
            }

            switch(choice) {
                case 1:
                {
                    N = N+const_n;
                }
                case 2:
                {
                    N=N+n_count;
                }
                case 3:
                {
                    break;
                }
            }

        }
    }while(fabs(x1-x2)>=eps);
    printf("\nX= %.3lf\tf(x)= %.3lf\n", xi, f(xi));
    return xi;
}

double chord (double x1, double x2, int n_count, int N, const double eps) {

    double xi, xl;
    unsigned int choice, const_n;
    const_n=N;

    do{
        n_count++;
        xl=xi;
        xi=x2-f(x2)*(x1-x2)/(f(x1)-f(x2));
        x1=x2;
        x2=xl;

        if (n_count%N==0) {

            printf ("Кількість виповнених ітерацій: %u", n_count);
            printf ("\n Поточний Х: %.3lf", xi);
            printf ("\n Поточна f(x)= %.3lf", f(xi));
            printf ("\n\n Виберіть що робити далі");

            printf ("\n\t 1 Продовжити з такою самою кількістю ітерацій");
            printf ("\n\t 2 Продовжити поки корінь не буде знайдено");
            printf ("\n\t 3 Вийти і показати поточний результат");

            scanf ("%u", &choice);
            printf ("==============================================================\n");

            while (choice!=1&&choice!=2&&choice!=3) {
                scanf("%u", &choice);
            }

            switch(choice) {
                case 1:
                {
                    N = N+const_n;
                }
                case 2:
                {
                    N=N+n_count;
                }
                case 3:
                {
                    break;
                }
            }
        }
    }while(fabs(xi-x2)>eps);
    printf ("\nX= %.3lf\tf(x)= %.3lf\n", xi, f(xi));
    return xi;
}

double f (double x) {
    return (2.00 * (pow((x - 1000.00), 3.00)) - (3.00 * pow((x - 500.00), 2.00)) +
                (4.00 * x - 5.00));
}
