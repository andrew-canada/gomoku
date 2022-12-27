val mysqlVersion: String by project

plugins {
    java
    application
    id("org.flywaydb.flyway") version "7.3.2"
}

group = "org.logoticket"
version = "1.0-SNAPSHOT"

repositories {
    mavenCentral()
}

dependencies {
    implementation("mysql:mysql-connector-java:$mysqlVersion")
}

application {
    mainClass.set("com.knowledgespike.Application")
}

flyway {
    url = "jdbc:mysql://localhost:3306/loboticket"
    user = "loboticket"
    password = "p4ssw0rd"
    schemas = arrayOf("loboticket")
    locations = arrayOf("filesystem:${projectDir}/migrations/mysql")
    sqlMigrationPrefix = ""
    baselineOnMigrate = true
    outOfOrder = true
}
