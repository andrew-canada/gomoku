package com.andrew.java.algo.sorting;

import java.util.Objects;

public class CashDonor extends Donor {

    private int moneyWeight;

    public CashDonor(String name, int donationAmount, int moneyWeight) {
        super(name, donationAmount);
        this.moneyWeight = moneyWeight;
    }

    public int getMoneyWeight() {
        return moneyWeight;
    }

    public void setMoneyWeight(int moneyWeight) {
        this.moneyWeight = moneyWeight;
    }

    @Override
    public String toString() {
        return "CashDonor [name=" + this.getName() + ", donation amount=" + this.getDonationAmount() + ", moneyWeight="
                + moneyWeight + "]";
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = super.hashCode();
        result = prime * result + Objects.hash(moneyWeight);
        return result;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (!super.equals(obj))
            return false;
        if (getClass() != obj.getClass())
            return false;
        CashDonor other = (CashDonor) obj;
        return moneyWeight == other.moneyWeight;
    }

    @Override
    public int compareTo(Donor other) {
        return this.moneyWeight - ((CashDonor) other).moneyWeight;
    }

}
