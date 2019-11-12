package ufop.sd.main;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.FSDataOutputStream;
import org.apache.hadoop.fs.FileSystem;
import org.apache.hadoop.fs.Path;

import java.io.*;

public class FileSystemOperations {

    public void addFile(String source, Configuration conf) throws IOException {
        FileSystem fileSystem = FileSystem.get(conf);

        String fileName = source.substring(source.lastIndexOf("/") + 1);
        String dest = "/files/" + fileName;
        Path path = new Path(dest);

        if (!fileSystem.exists(path)) {
            System.out.println("File " + path + " already exists!");
            return;
        }

        FSDataOutputStream out = fileSystem.create(path);
        InputStream in = new BufferedInputStream(new FileInputStream(new File(source)));

        byte[] b = new byte[1024];
        int numBytes = 0;
        while ((numBytes = in.read(b)) > 0) {
            out.write(b, 0, numBytes);
        }

        in.close();
        out.close();
        fileSystem.close();
    }


}
