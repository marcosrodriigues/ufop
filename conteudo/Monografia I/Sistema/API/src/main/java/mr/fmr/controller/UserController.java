package mr.fmr.controller;

import mr.fmr.model.User;
import mr.fmr.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.web.bind.annotation.*;

import java.security.Principal;
import java.util.List;

@RestController
@RequestMapping
public class UserController {

    final String BASE_URL = "/user";

    @Autowired
    private UserService userService;

    @GetMapping(value = BASE_URL)
    public List listUser() {
        return userService.findAll();
    }

    @PostMapping(value = BASE_URL)
    public User create(@RequestBody User user) {
        return userService.save(user);
    }

    @GetMapping(value = BASE_URL + "/{id}")
    public User findOne(@PathVariable long id) {
        return userService.findOne(id);
    }

    @GetMapping(value = BASE_URL + "/me")
    @ResponseBody
    public User findMe(Principal principal) {
        return userService.getUserFromPrincipal(principal);
    }

    @PutMapping(value = BASE_URL + "/{id}")
    public User update(@PathVariable long id, @RequestBody User user) {
        user.setId(id);
        return userService.save(user);
    }

    @DeleteMapping(value = BASE_URL + "/{id}")
    public void delete(@PathVariable long id) {
        userService.delete(id);
    }
}
