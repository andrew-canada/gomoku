package com.andrew.annotations;

import java.lang.annotation.ElementType;
import java.lang.annotation.Repeatable;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

@Retention(RetentionPolicy.RUNTIME)
@Target({ ElementType.CONSTRUCTOR, ElementType.METHOD, ElementType.TYPE })
@Repeatable(Versions.class)
public @interface Version {
	int value() default 1;

	String author() default "Andrew";

	String license() default "MIT";

	String[] environments() default { "production", "development" };
}
