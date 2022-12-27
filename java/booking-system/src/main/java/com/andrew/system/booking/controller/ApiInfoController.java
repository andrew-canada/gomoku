package com.andrew.system.booking.controller;

import java.util.Map;

import javax.servlet.http.HttpServletResponse;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/")
public class ApiInfoController {

	@Value("#{${api.info}}")
	private Map<String, String> apiInfo;

	@Value("${api.name}")
	private String apiName;

	@GetMapping(value = "apiInfo")
	public Map<String, String> getApiInfo1(HttpServletResponse response) {
		return apiInfo;
	}

	@GetMapping(value = "name")
	public String getApiName(HttpServletResponse reponse) {
		return apiName;
	}
}
