package com.andrew.java.algo.sorting;

import javax.script.ScriptEngine;
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;

public class JSEngine {

    public static void main(String[] args) {
        ScriptEngineManager mgr = new ScriptEngineManager();
        ScriptEngine engine = mgr.getEngineByName("graal.js"); // "cheat"
        try {
            System.out.println(engine.eval("3 + (8 - 7.5) * 10 / 5 - (2 + 5 * 7)"));
        } catch (ScriptException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

    }

}
