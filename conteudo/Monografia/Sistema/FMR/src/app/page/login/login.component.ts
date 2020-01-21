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


  loginSendingSignIn = false;
  loginCallbackMessageSignIn = '';
  loginCallbackClassSignIn = 'danger';

  loginSendingSignUp = false;
  loginCallbackMessageSignUp = '';
  loginCallbackClassSignUp = 'danger';
  

  constructor(private userService: UserService,
              private _router : Router ) { }

  ngOnInit() {
  }

  signIn() {
    this.loginSendingSignIn = true;
    this.userService.login(this.login).subscribe(data => {
      this.userService.saveToken(data);
      this.loginSendingSignIn = false;
      window.location.href = '/';
    }, err => {
      this.loginCallbackMessageSignIn = 'Usuário e/ou senha incorretos!';
      this.loginCallbackClassSignIn = 'danger';
      this.loginSendingSignIn = false;
    })
  }

  signUp() {
    this.loginCallbackMessageSignUp = '';
    if (this.user.tipo == '') {
      this.loginCallbackMessageSignUp += "Tipo deve ser preenchido!";
    }
    if (this.user.email == '') {
      this.loginCallbackMessageSignUp += "Email deve ser preenchido!";
    }
    if (this.user.password == '') {
      this.loginCallbackMessageSignUp += "Password deve ser preenchido!\n";
    }
    if (!this.user.termos) {
      this.loginCallbackMessageSignUp += 'Leia os termos de uso!\n';
    }

    if (this.loginCallbackMessageSignUp != '') {
      return;
    }

    this.loginSendingSignUp = true;
    this.userService.create(this.user).subscribe(data => {
      this.loginCallbackMessageSignUp = 'Usuário criado com sucesso. Você já pode fazer login!';
      this.loginCallbackClassSignUp = 'success';
      this.loginSendingSignUp = false;
    }, err => {
      this.loginCallbackMessageSignUp = err.error.message;
      this.loginCallbackClassSignUp = 'danger';
      this.loginSendingSignUp = false;
    })
  }
}
