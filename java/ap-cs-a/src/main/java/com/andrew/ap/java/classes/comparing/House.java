package com.andrew.ap.java.classes.comparing;

public class House {

    private String color;
    private int size;
    private int numRooms;

    public House(String color, int size, int numRooms) {
        this.color = color;
        this.size = size;
        this.numRooms = numRooms;
    }

    @Override
    public boolean equals(Object otherHouse) {
        if (this == otherHouse) {
            return true;
        }
        return ((otherHouse instanceof House newHouse) && color.equals(newHouse.getColor())
                && this.size == newHouse.getSize()
                && this.numRooms == newHouse.getNumRooms());

    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public int getNumRooms() {
        return numRooms;
    }

    public void setNumRooms(int numRooms) {
        this.numRooms = numRooms;
    }
}
