package com.andrew.system.booking.controller;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.andrew.system.booking.flight.FlightPlan;

@RestController
@RequestMapping("/flightplan")
public class FlightController {

	@GetMapping(value = "/flightplan")
	public FlightPlan getFlightPlan(String departure, String arrival) {
		return new FlightPlan(departure, arrival);
	}
}
