package mr.fmr.exception;

import org.springframework.http.HttpStatus;
import org.springframework.web.bind.annotation.ResponseStatus;

@ResponseStatus(HttpStatus.CONFLICT)
public class MyUnauthorizedException extends RuntimeException {

    public MyUnauthorizedException(String message) {
        super(message);
    }

    public MyUnauthorizedException(String message, Throwable cause) {
        super(message, cause);
    }
}
