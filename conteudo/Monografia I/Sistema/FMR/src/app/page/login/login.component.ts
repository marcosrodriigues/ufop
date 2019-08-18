import { Component, OnInit } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { UserService } from 'src/app/service/user.service';

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.css']
})
export class LoginComponent implements OnInit {

  public login = {
    scope:'read',
    grant_type:'password',
    username: '',
    password: ''
  }

  user = {
    tipo: '',
    email: '',
    password: '',
    termo: false
  }

  constructor(private http: HttpClient,
              private userService: UserService) { }

  ngOnInit() {
  }

  signIn() {
    window.localStorage['username'] = 'hello';
    const param = JSON.stringify(this.login);
    this.userService.login(param).subscribe(data => {
      console.log(data);
      console.log(param);
    })
  }

  signUp() {
    const param = JSON.stringify(this.user);
    console.log(param);
    this.userService.create(this.user).subscribe(data => {
      console.log(data);
    })
  }

  url = 'http://localhost:8080/login';
  signUpFacebook() {
    this.http.post(this.url, {}).subscribe(d => {
      console.log(d);
    })
  }

}
