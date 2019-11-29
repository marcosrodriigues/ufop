import { Component, OnInit } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { UserService } from 'src/app/service/user.service';
import { Router } from '@angular/router';

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

  errorSignIn = '';
  errorSignUp = '';
  okSignUp = '';
  waitSignIn = false;
  waitSignUp = false;

  constructor(private userService: UserService,
              private _router : Router ) { }

  ngOnInit() {
  }

  signIn() {
    this.userService.login(this.login).subscribe(data => {
      this.userService.saveToken(data);
      window.location.href = '/';
    }, err => {
      this.errorSignIn = 'Usuário e/ou senha incorretos!';
    })
  }

  signUp() {
    this.errorSignUp = '';
    if (!this.user.termos) {
      this.errorSignUp = 'Leia os termos de uso!'
      return;
    }
    this.waitSignUp = true;
    this.userService.create(this.user).subscribe(data => {
      this.okSignUp = 'Usuário criado com sucesso. Você já pode fazer login!';
      this.waitSignUp = false;
    }, err => {
      this.errorSignUp = err.message;
    })
  }
}
