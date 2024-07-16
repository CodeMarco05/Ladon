package org.marco;

import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

public class Ladon {
    static boolean hadError = false;


    public static void main(String[] args) throws IOException {
        //print current working dir
        System.out.println(System.getProperty("user.dir"));

        if (args.length > 1){
            System.out.println("Usage: ladon [script]");
            System.exit(64);
        } else if (args.length == 1) {
            runFile(args[0]);
        } else {
            System.out.println("Welcome to Ladon!");
            if (hadError) System.exit(65);
        }
    }

    private static void runFile(String path) throws IOException{
        //get the input from the file
        byte[] bytes = Files.readAllBytes(Paths.get(path));
        //send the input to the interpreter1
        run(new String(bytes, Charset.defaultCharset()));
    }

    private static void run(String source){
        Scanner scanner = new Scanner(source);
        List<Token> tokens = scanner.scanTokens();

        //print tokens
        for (Token token : tokens){
            System.out.println(token);
        }
    }

    static void error(int line, String message){
        report(line, "", message);
    }

    private static void report(int line, String where, String message){
        System.err.println("[line " + line + "] Error" + where + ": " + message);
    }
}