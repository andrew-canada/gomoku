package com.andrew.ap.java.strings;

public class StringTester {

    public static void main(String[] args) {
        String name1 = "joe";
        String name2 = new String("john");
        String name3 = new String(name1);
        String newString;
        int age1 = 5434;
        String combinedName = name1 + " " + name2;
        String info1 = name1;
        info1 += age1;

        System.out.println(name1);
        System.out.println(name2);
        System.out.println(name3);
        System.out.println(combinedName);
        System.out.println(info1);
        System.out.println(info1.matches("(joe).*"));
        System.out.println("\"abc\\ \n def");
        System.out.println("\"" + name1 + "\\");

        System.out.println("string methods: ");
        System.out.println(name3.length());

        newString = name1.substring(name1.length() - 1);
        newString += name2.substring(0, 2);
        System.out.println(newString);

        System.out.println(name1.indexOf("j"));
        System.out.println(name1.indexOf("jo"));
        System.out.println(name1.indexOf("x"));

        System.out.println(name1.equals(info1));
        System.out.println(name1.equals(name3));

        String name1Ref = name1;
        System.out.println(name1.equals(name1Ref));

        System.out.println(name1.compareTo(name2));
        System.out.println(name1.compareTo(name3));
        System.out.println("abc".compareTo("abd"));
        System.out.println("abe".compareTo("abd"));

    }

}
