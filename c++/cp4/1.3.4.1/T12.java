import javax.script.ScriptEngineManager;
import javax.script.ScriptEngine;

public class T12 {
    public static void main(String[] args) throws Exception {
        ScriptEngineManager sem = new ScriptEngineManager();
        ScriptEngine se = sem.getEngineByName("Nashorn");
        System.out.println(se.eval("3 + (8 - 7.5) * 10 / 5 - (2 + 5 * 7)"));
    }
}