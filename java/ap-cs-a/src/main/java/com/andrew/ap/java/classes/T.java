package com.andrew.ap.java.classes;

public class T {
    private T t = null;

    private T() {

    }

    public synchronized T getInstance() {
        if (t == null) {
            t = new T();
        }
        return t;
    }
}
