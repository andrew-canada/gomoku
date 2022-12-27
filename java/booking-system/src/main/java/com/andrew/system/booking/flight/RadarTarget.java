package com.andrew.system.booking.flight;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class RadarTarget {

	private String callSign;
	private String model;
	private int flightLevel;
	private int requiredFlightLevel;

	public RadarTarget(String callSign, String model, int flightLevel) {
		this.callSign = callSign;
		this.model = model;
		this.flightLevel = flightLevel;
		this.requiredFlightLevel = flightLevel;
	}

	public String getLabel() {
		StringBuilder sb = new StringBuilder();
		sb.append(callSign);
		sb.append(System.lineSeparator());
		sb.append(flightLevel);
		sb.append(getClimbDescendIndicator());
		sb.append(requiredFlightLevel);
		sb.append(System.lineSeparator());
		sb.append(model);
		return sb.toString();
	}

	@Override
	public String toString() {
		return "RadarTarget [callSign=" + callSign + ", model=" + model + ", flightLevel=" + flightLevel
				+ ", requiredFlightLevel=" + requiredFlightLevel + "]";
	}

	public String getClimbDescendIndicator() {
		if (flightLevel < requiredFlightLevel) {
			return "▲";
		}
		if (flightLevel > requiredFlightLevel) {
			return "▼";
		}
		return "=";
	}

	public void changeAltitude(int newFlightLevel) {
		requiredFlightLevel = newFlightLevel;

		ExecutorService es = Executors.newSingleThreadExecutor();
		es.execute(() -> {
			try {
				Thread.sleep((long) (Math.random() * 5 * 1000));
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			this.flightLevel = requiredFlightLevel;
		});

		es.shutdown();
	}
}
