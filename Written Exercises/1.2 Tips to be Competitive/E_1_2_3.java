import javax.script.ScriptEngine;
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;

class E_1_2_3 {
	
	public void no1() {
		double d = 1.4732;
		System.out.printf("%7.3f", d);
	}
	
	public void no11() {
		String s = "3 + (8 - 7.5) * 10 / 5 - (2 + 5 * 7)";
		ScriptEngineManager mgr = new ScriptEngineManager();
		ScriptEngine engine = mgr.getEngineByName("JavaScript");
		try {
			System.out.println(engine.eval(s));
		} catch (ScriptException e) {
			e.printStackTrace();
		}
	}
}
