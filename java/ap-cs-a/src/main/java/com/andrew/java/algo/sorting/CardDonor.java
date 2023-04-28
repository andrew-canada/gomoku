package com.andrew.java.algo.sorting;

import java.util.Objects;

public class CardDonor extends Donor {
	private int pin;

	public CardDonor(String name, int donationAmount, int pin) {
		super(name, donationAmount);
		this.pin = pin;
	}

	public int getPin() {
		return pin;
	}

	public void setPin(int pin) {
		this.pin = pin;
	}

	@Override
	public String toString() {
		return "CardDonor [pin=" + pin + "]";
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = super.hashCode();
		result = prime * result + Objects.hash(pin);
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
		CardDonor other = (CardDonor) obj;
		return pin == other.pin;
	}

	@Override
	public int compareTo(Donor other) {
		return this.pin - ((CardDonor) other).pin;
	}

}
