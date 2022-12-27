package com.andrew.ap.java.variables.casting;

public class CastingTest {

    public static void main(String[] args) {
        int num1 = 10;
        int num2 = 3;

        int intQuotient = num1 / num2;
        double doubleQuotient = (double) num1 / num2;
        System.out.println(intQuotient);
        System.out.println(doubleQuotient);

        double num3 = 11;
        double num4 = 3;
        int quotient = (int) (num3 / num4);
        int roundedQuotient = (int) (num3 / num4 + 0.5);
        System.out.println(quotient);
        System.out.println(roundedQuotient);

        double num5 = -11;
        double num6 = 3;
        int negQuotient = (int) (num5 / num6);
        int negRoundedQuotient = (int) (num5 / num6 - 0.5);
        System.out.println(negQuotient);
        System.out.println(negRoundedQuotient);

        int maxInt = Integer.MAX_VALUE;
        System.out.println(maxInt);
        int overFlowedInt = Integer.MAX_VALUE + 1;
        System.out.println(overFlowedInt);

        double maxDouble = Double.MAX_VALUE;
        System.out.println(maxDouble);
        System.out.println(maxDouble + 1);

        double underFlowDouble = Math.pow(10, -1000);
        System.out.println(underFlowDouble);

    }

}
