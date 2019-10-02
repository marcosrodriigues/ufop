package mr.fmr.exception;

import org.springframework.http.HttpStatus;
import org.springframework.web.bind.annotation.ResponseStatus;

@ResponseStatus(HttpStatus.BAD_REQUEST)
public class MyBadRequestException extends RuntimeException {

    public MyBadRequestException(String message) {
        super(message);
    }

    public MyBadRequestException(String message, Throwable cause) {
        super(message, cause);
    }
}
