package com.pluralsight;

import sun.security.x509.X500Name;

public class Legacy {

  public static void main(String... args) throws Exception {
    X500Name name = new X500Name("test.com", "test", "test", "US");
    System.out.println(name);
  }

}
