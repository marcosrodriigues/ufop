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
    username: '',
    password: ''
  }

  user = {
    tipo: '',
    email: '',
    password: '',
    termos: false
  }

  constructor(private userService: UserService) { }

  ngOnInit() {
  }

  signIn() {
    const param = JSON.stringify(this.login);
    this.userService.login(this.login).subscribe(data => {
      this.userService.saveToken(data);
    }, err => {
      alert('Invalid credentials');
    })
  }

  signUp() {
    const param = JSON.stringify(this.user);
    this.userService.create(this.user).subscribe(data => {
      alert('Usuário criado!');
    })
  }
}
