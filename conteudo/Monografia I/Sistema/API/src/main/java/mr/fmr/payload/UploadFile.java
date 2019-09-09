package mr.fmr.payload;

public class UploadFile {

    private String filename;
    private String fileUri;
    private String fileType;
    private long size;

    public UploadFile(String filename, String fileUri, String fileType, long size) {
        this.filename = filename;
        this.fileUri = fileUri;
        this.fileType = fileType;
        this.size = size;
    }

    public String getFilename() {
        return filename;
    }

    public void setFilename(String filename) {
        this.filename = filename;
    }

    public String getFileUri() {
        return fileUri;
    }

    public void setFileUri(String fileUri) {
        this.fileUri = fileUri;
    }

    public String getFileType() {
        return fileType;
    }

    public void setFileType(String fileType) {
        this.fileType = fileType;
    }

    public long getSize() {
        return size;
    }

    public void setSize(long size) {
        this.size = size;
    }
}
