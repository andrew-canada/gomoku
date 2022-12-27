package com.pluralsight;

public class Widget<T> {
    public static void main(String... args) {
        Widget<String> widget = new Widget<>();
        widget.setType("hello");

        Widget widget2 = new Widget<>();
        Widget widget3 = new Widget();

        String [] strings = new String[]{"Hi", "There"};
        System.out.println(Widget.firstArrayElement(strings));

    }

    private T type;

    public T getType() {
        return type;
    }

    public void setType(T type) {
        this.type = type;
    }

    public static <T> T firstArrayElement(T[] t){
        //if there is a first element return it
        if (t.length > 0) {
            return t[0];
        }
        //otherwise return null
        return null;
    }

}
