package com.andrew.lambda;

/*
 * "this" 
 * 		-in anonymous class: refers to instance of anonymous class
 * 		-in lambda: explicitly access member variables (same with super)
 */

public class LambdasWithEnclosingCode {

	public static void main(String[] args) {

		LambdasWithEnclosingCode lwec = new LambdasWithEnclosingCode();

		ThreadExample te = lwec.new ThreadExample();
		te.printMessage();

		LambdaExample le = lwec.new LambdaExample();
		le.printMessage();
	}

	public class ThreadExample {
		public void printMessage() {
			// anonymous class
			Runnable runnable = new Runnable() {
				private String message = "Hello World in ThreadExample";

				@Override
				public void run() {
					// references new anonymous Runnable class instance
					System.out.println(this.message);
				}
			};

			new Thread(runnable).start();
		}
	}

	public class LambdaExample {
		private String message = "Hello World in LambdaExample";

		public void printMessage() {
			// accesses member var "message"
			Runnable runnable = () -> System.out.println(this.message);

			new Thread(runnable).start();
		}
	}

}
