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

  signUpAvailable = true;
  signInAvailable = true;

  constructor(private userService: UserService,
              private _router : Router ) { }

  ngOnInit() {
  }

  signIn() {
    this.signInAvailable = false;
    this.userService.login(this.login).subscribe(data => {
      this.userService.saveToken(data);
      this.signInAvailable = true;
      window.location.href = '/';
    }, err => {
      this.errorSignIn = 'Usuário e/ou senha incorretos!';
      this.signInAvailable = true;
    })
  }

  signUp() {
    this.errorSignUp = '';
    if (this.user.tipo == '') {
      this.errorSignUp += "Tipo deve ser preenchido!";
    }
    if (this.user.email == '') {
      this.errorSignUp += "Email deve ser preenchido!";
    }
    if (this.user.password == '') {
      this.errorSignUp += "Password deve ser preenchido!\n";
    }
    if (!this.user.termos) {
      this.errorSignUp += 'Leia os termos de uso!\n';
    }

    if (this.errorSignUp != '') {
      return;
    }

    this.signUpAvailable = false;
    this.userService.create(this.user).subscribe(data => {
      this.okSignUp = 'Usuário criado com sucesso. Você já pode fazer login!';
      this.signUpAvailable = true;
    }, err => {
      this.errorSignUp = err.error.message;
      this.signUpAvailable = true;
    })
  }
}
