public class Stunnel { 
    public native int begin(String config);
    static { System.loadLibrary("stunnel"); }
    public static void main (String[] args) { 
        String configFile = args[0];

        Stunnel stunnel = new Stunnel(); 
        stunnel.begin(configFile);
    }
}
