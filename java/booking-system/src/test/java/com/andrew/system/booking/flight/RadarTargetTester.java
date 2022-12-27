package com.andrew.system.booking.flight;

public class RadarTargetTester {

	public static void main(String[] args) throws InterruptedException {
		RadarTarget rt = new RadarTarget("AC276", "A380", 100);
		System.out.println(rt.getLabel());
		System.out.println();

		rt.changeAltitude(200);

		for (int i = 0; i < 5; i++) {
			Thread.sleep(1000);
			System.out.println(rt.getLabel());
			System.out.println();
		}
	}

}
