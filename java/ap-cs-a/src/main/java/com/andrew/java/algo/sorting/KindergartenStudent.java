package com.andrew.java.algo.sorting;

import java.util.Objects;

public class KindergartenStudent extends Student {

    private int napDuration;

    public KindergartenStudent(int id, String name, int napDuration) {
        super(id, name);
        this.napDuration = napDuration;
    }

    public int getNapDuration() {
        return napDuration;
    }

    public void setNapDuration(int napDuration) {
        this.napDuration = napDuration;
    }

    @Override
    public String toString() {
        return "Student [id=" + this.getId() + ", name=" + this.getName() + ", nap duration=" + napDuration + "]";
    }

    @Override
    public boolean equals(Object other) {
        if (this == other) {
            return true;
        } else if (other == null) {
            return false;
        } else if (this.getClass() != other.getClass()) {
            return false;
        }
        KindergartenStudent ks = (KindergartenStudent) other;
        return this.getId() == ks.getId() && this.napDuration == ks.napDuration
                && Objects.equals(this.getName(), ks.getName());
    }

    @Override
    public int hashCode() {
        return Objects.hash(this.getId(), this.getName(), napDuration);
    }

    @Override
    public int compareTo(Student other) {
        return this.napDuration - ((KindergartenStudent) other).napDuration;
    }

}
