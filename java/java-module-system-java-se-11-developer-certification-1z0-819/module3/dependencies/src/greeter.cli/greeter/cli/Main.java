package greeter.cli;

import greeter.hello.service.HelloMessageService;

public class Main {
  public static void main(String... args) {
    HelloMessageService messageService =
       new HelloMessageService();
    String message = messageService.getMessage();
    System.out.println(message + " from a module!");
  }
}
