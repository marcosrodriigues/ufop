package mr.fmr.controller;

import mr.fmr.model.User;
import mr.fmr.payload.UploadFile;
import mr.fmr.service.StorageService;
import mr.fmr.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.core.io.Resource;
import org.springframework.http.HttpHeaders;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;
import org.springframework.web.servlet.support.ServletUriComponentsBuilder;

import javax.servlet.http.HttpServletRequest;
import java.io.IOException;
import java.security.Principal;

@RestController
@RequestMapping
public class UploadController {

    private final String BASE_URL = "/upload";

    @Autowired
    private StorageService service;
    @Autowired private UserService userService;

    @PostMapping(value = BASE_URL)
    public UploadFile fileUpload(Principal principal, @RequestParam  MultipartFile file) {
        String filename = service.store(file);

        String fileUri = ServletUriComponentsBuilder.fromCurrentContextPath()
                .path("/upload/")
                .path(filename)
                .toUriString();

        UploadFile uploadFile = new UploadFile(filename, fileUri, file.getContentType(), file.getSize());

        User user = userService.getUserFromPrincipal(principal);
        user.setFotoUrl(uploadFile.getFileUri());
        userService.save(user);

        return uploadFile;
    }

    @GetMapping(value = BASE_URL + "/{filename:.+}")
    @ResponseBody
    public ResponseEntity<Resource> getOne(HttpServletRequest request, @PathVariable String filename) {

        Resource resource = service.loadAsResource(filename);

        // Try to determine file's content type
        String contentType = null;
        try {
            contentType = request.getServletContext().getMimeType(resource.getFile().getAbsolutePath());
        } catch (IOException ex) {
            //log.info("Could not determine file type.");
        }

        if(contentType == null) {
            contentType = "application/octet-stream";
        }

        return ResponseEntity.ok()
                .contentType(MediaType.parseMediaType(contentType))
                .header(HttpHeaders.ACCEPT, "filename=\"" + resource.getFilename() + "\"")
                .body(resource);

    }
}
