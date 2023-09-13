
#include <stdio.h>

int main()
{
    int choice,a1,a2,b1,b2;
    float a3,b3;
    printf("-------------------Welcome------------------\n");
    printf("\nThis is a program to do the folloing operations of complex numbers:\n");
    printf("\n1. Addition of complex numbers.");
    printf("\n2. Stutraction of complex numbers.");
    printf("\n3. Multiplication of complex numbers.");
    printf("\n4. Division of complex numbers.\n");
    printf("\nEnter your choice:");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
        printf("Enter the real and imaginary part of the first complex number:");
        scanf("%d %d", &a1, &b1);
        printf("Enter the real and imaginary part of the first complex number:");
        scanf("%d %d", &a2, &b2);
        a3=a1+a2;
        b3=b1+b2;
        printf("The sum of the given complex numbers is: %.1f + %.1fi",a3,b3);
        break;

        case 2:
        printf("Enter the real and imaginary part of the first complex number:");
        scanf("%d %d", &a1, &b1);
        printf("Enter the real and imaginary part of the first complex number:");
        scanf("%d %d", &a2, &b2);
        a3=a1-a2;
        b3=b1-b2;
        if(b3>=0)
            printf("The difference of the given complex numbers is: %.1f + %.1fi",a3,b3);
        else
            printf("The difference of the given complex numbers is: %.1f %.1fi",a3,b3);
        break;

        case 3:
        printf("Enter the real and imaginary part of the first complex number:");
        scanf("%d %d", &a1, &b1);
        printf("Enter the real and imaginary part of the first complex number:");
        scanf("%d %d", &a2, &b2);
        a3=a1*a2-b1*b2;
        b3=a1*b2+b1*a2;
        printf("The product of the given complex numbers is: %.1f + %.1fi",a3,b3);
        break;

        case 4:
        printf("Enter the real and imaginary part of the first complex number:");
        scanf("%d %d", &a1, &b1);
        printf("\nEnter the real and imaginary part of the first complex number:");
        scanf("%d %d", &a2, &b2);
        a3=(a1*a2+b1*b2)/(a2*a2+b2*b2);
        b3=(b1*a2-a1*b2)/(a2*a2+b2*b2);
        printf("The quotient of the given complex numbers is: %.1f + %.1fi",a3,b3);
        break;

        default:
        printf("Invalid choice!");

    }

    return 0;
}