package com.andrew.ap.java.classes;

public class Cow {

    private String type;
    private String sound;
    private int numMilkings;

    public Cow(String type, String sound) {
        this.type = type;
        this.sound = sound;
    }

    public void milkCow() {
        this.numMilkings += 1;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public String getSound() {
        return sound;
    }

    public void setSound(String sound) {
        this.sound = sound;
    }

    public int getNumMilkings() {
        return numMilkings;
    }

    public void setNumMilkings(int numMilkings) {
        this.numMilkings = numMilkings;
    }
}
