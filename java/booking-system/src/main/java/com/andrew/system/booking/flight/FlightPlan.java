package com.andrew.system.booking.flight;

import java.time.LocalDateTime;
import java.util.List;
import java.util.UUID;

public class FlightPlan {

	private String departure;
	private String arrival;
	private String id;
	private List<String> route;
	private LocalDateTime time;

	private FlightPlan() {
		this.id = UUID.randomUUID().toString();
	}

	public FlightPlan(String departure, String arrival) {
		this();
		this.departure = departure;
		this.arrival = arrival;
	}

	public String getDeparture() {
		return departure;
	}

	public void setDeparture(String departure) {
		this.departure = departure;
	}

	public String getArrival() {
		return arrival;
	}

	public void setArrival(String arrival) {
		this.arrival = arrival;
	}

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public List<String> getRoute() {
		return route;
	}

	public void setRoute(List<String> route) {
		this.route = route;
	}

	public LocalDateTime getTime() {
		return time;
	}

	public void setTime(LocalDateTime time) {
		this.time = time;
	}

}
