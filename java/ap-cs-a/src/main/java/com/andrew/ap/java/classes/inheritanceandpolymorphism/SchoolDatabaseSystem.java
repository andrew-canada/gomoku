package com.andrew.ap.java.classes.inheritanceandpolymorphism;

import java.util.List;

public class SchoolDatabaseSystem {
    private List<Person> members;

    public SchoolDatabaseSystem(List<Person> members) {
        this.members = members;
    }

    public void addMember(Person p) {
        members.add(p);
    }

    public Person getMember(int index) {
        return members.get(index);
    }

    public List<Person> getMembers() {
        return members;
    }
}
