package ufop.sd.main;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.LocalFileSystem;
import org.apache.hadoop.hdfs.DistributedFileSystem;
import org.apache.spark.sql.Dataset;
import org.apache.spark.sql.SparkSession;

import java.io.IOException;
import java.util.regex.Pattern;

public class SampleClass {

    private static final Pattern SPACE = Pattern.compile(" ");
   // private static final String HDFS_PATH = "hdfs://master/";
   private static final String HDFS_PATH = "/home/marcos/";

    public static void main(String[] args) {

        //  CONFIGURAÇÃO DO HADOOP
        //initHadoopConfig();

        //Hello world!
        String logFile = "downloads/spark/README.md"; // Should be some file on your system
        SparkSession spark = SparkSession.builder().appName("SimpleApp")
                .master("local[*]").getOrCreate();

        Dataset<String> logData = spark.read().textFile(HDFS_PATH + logFile).cache();

        long numAs = logData.filter(line -> line.contains("a")).count();
        long numBs = logData.filter(line -> line.contains("b")).count();

        System.out.println("Lines with a: " + numAs + ", lines with b: " + numBs);

        //Extra pra brincar
        long numTitles = logData.filter(line -> line.startsWith("#")).count();
        System.out.println("O documento tem " + numTitles + " títulos");

        /*JavaPairRDD<String, Integer> counts = logData
                .flatMap(s -> Arrays.asList(s.split("[ ,]")).iterator())
                .mapToPair(word -> new Tuple2<>(word, 1))
                .reduceByKey((a, b) -> a + b);
        counts.foreach(p -> System.out.println(p));
        System.out.println("Total words: " + counts.count());
        counts.saveAsTextFile("/tmp/shakespeareWordCount");
        */
        //Contador de palavras
        //JavaPairRDD<String, Integer> counts = logData.flatMap(s -> Arrays.asList(s.split("[ ,]")).iterator())

        spark.stop();
    }

    private static void initHadoopConfig() {
        try {
            Configuration conf = new Configuration();
            conf.set("fs.defaultFS", HDFS_PATH);

            conf.set("fs.hdfs.impl", DistributedFileSystem.class.getName());
            conf.set("fs.file.impl", LocalFileSystem.class.getName());

            System.out.println(conf.get("fs.default.name"));

            FileSystemOperations operations = new FileSystemOperations();

            String source = "/home/marcos/19.2/Sistemas Distribuídos/spark/README.md";

            operations.addFile(source, conf);
        } catch (IOException e) {
            System.err.println(e.getMessage());
            return;
        }
    }
}
