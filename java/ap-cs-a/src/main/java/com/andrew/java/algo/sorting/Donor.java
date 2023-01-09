package com.andrew.java.algo.sorting;

import java.util.Objects;

public class Donor implements Comparable<Donor> {

    private String name;
    private int donationAmount;

    public Donor(String name, int donationAmount) {
        this.name = name;
        this.donationAmount = donationAmount;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getDonationAmount() {
        return donationAmount;
    }

    public void setDonationAmount(int donationAmount) {
        this.donationAmount = donationAmount;
    }

    @Override
    public String toString() {
        return "Donor [name=" + name + ", donationAmount=" + donationAmount + "]";
    }

    @Override
    public int compareTo(Donor o) {
        return this.donationAmount - o.donationAmount;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        } else if (obj == null) {
            return false;
        } else if (this.getClass() != obj.getClass()) {
            return false;
        }
        Donor donor = (Donor) obj;
        // must check if name is non-null
//        return this.donationAmount == donor.donationAmount && (this.name != null &&
//                this.name.equals(donor.getName()));

        // Objects.equals() checks for null
        return this.donationAmount == donor.donationAmount &&
                Objects.equals(this.name, donor.name);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, donationAmount);
    }
}
