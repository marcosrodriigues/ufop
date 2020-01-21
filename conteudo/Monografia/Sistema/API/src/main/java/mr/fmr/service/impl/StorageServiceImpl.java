package mr.fmr.service.impl;

import mr.fmr.exception.FileStorageException;
import mr.fmr.exception.MyFileNotFoundException;
import mr.fmr.pojo.FileStorageProperties;
import mr.fmr.service.StorageService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.core.io.Resource;
import org.springframework.core.io.UrlResource;
import org.springframework.stereotype.Service;
import org.springframework.util.StringUtils;
import org.springframework.web.multipart.MultipartFile;

import java.io.File;
import java.io.IOException;
import java.net.MalformedURLException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

@Service
public class StorageServiceImpl implements StorageService {

    private Path fileStorageLocation;

    @Autowired
    public StorageServiceImpl(FileStorageProperties properties) {
        this.fileStorageLocation = Paths.get(properties.getUploadDir()).toAbsolutePath().normalize();

        try {
            Files.createDirectories(this.fileStorageLocation);
        } catch (Exception e) {
            throw new FileStorageException("Não foi possível criar o caminho");
        }
    }


    @Override
    public String store(MultipartFile file) {
        String filename = StringUtils.cleanPath(file.getOriginalFilename());

        try {
            if(filename.contains("..")) {
                throw new FileStorageException("Filename contém caminho inválido");
            }

            Path targetLocation = this.fileStorageLocation.resolve(filename);

            int count = 1;
            while(targetLocation.toFile().exists()) {
                String fullPathWithoutFilename = "/";
                for (String tinyPath : targetLocation.toFile().getAbsolutePath().split("/")) {
                    if (!tinyPath.isEmpty())
                        fullPathWithoutFilename += tinyPath + "/";

                    if (tinyPath.equalsIgnoreCase("upload")) break;
                }

                String fullname = targetLocation.toFile().getName();
                String name = fullname.split("\\.")[0];
                String ext = fullname.split("\\.")[1];
                filename = name + "_" + count + "." + ext;
                File novoFile = new File(fullPathWithoutFilename + filename);

                targetLocation.toFile().renameTo(novoFile);
            }

            Files.copy(file.getInputStream(), targetLocation);

            return filename;
        } catch (IOException e) {
            throw new FileStorageException("Não foi possível armazenar o arquivo" + filename + "!Tente novamente", e);
        }
    }


    @Override
    public Resource loadAsResource(String filename) {
        try {
            Path file = this.fileStorageLocation.resolve(filename).normalize();

            Resource resource = new UrlResource(file.toUri());

            if (resource.exists()) {
                return resource;
            }

            throw new MyFileNotFoundException("Arquivo " + filename + " não encontrado!");
        } catch (MalformedURLException e) {
            throw new MyFileNotFoundException("Arquivo " + filename + " não encontrado!", e);
        }
    }
}
