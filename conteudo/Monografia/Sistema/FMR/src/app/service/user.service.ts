import { Injectable } from '@angular/core';
import { HttpClient, HttpParams } from '@angular/common/http';
import { Router } from '@angular/router';
import { CookieService } from 'ngx-cookie-service';
import { UrlService } from './default/url.service';

@Injectable({
  providedIn: 'root'
})
export class UserService {

  constructor(private _router : Router,
              private _http : HttpClient,
              private _cookie : CookieService,
              private _url : UrlService ) { }

  private baseUrl : string =  this._url.baseUrl() +"/user";
  private baseEstudante : string =  this._url.baseUrl() + "/estudante";
  private baseRepublica : string =  this._url.baseUrl() + "/republica";

  login(loginData) {
    let params = new HttpParams()
      .set('username', loginData.username)
      .set("password", loginData.password)
      .set("grant_type", "password")
      .set("scope", "read");

    const headers = {
      'Authorization': 'Basic ' + btoa('frm-client:frm-secret'),
      'Content-type': 'application/x-www-form-urlencoded'
    }

    return this._http.post(this._url.baseUrl() + '/oauth/token', params, {headers});
  }

  delete() {
    return this._http.delete(this.baseUrl);
  }

  saveToken(token) {
    var expiredDate = new Date().getTime(); + (token.expires_in);
    this._cookie.set('access_token', token.access_token, (token.expires_in / 24 / 60 / 60) );
  }

  checkCredentials() {
    if (!this._cookie.check('access_token'))
      this._router.navigate(['login']);
  }

  isLogged() {
    return this._cookie.check('access_token');
  }

  getToken() {
    return this._cookie.get('access_token');
  }

  getExpiresIn() {
    return this._cookie.check('access_token');
  }

  logout() {
    this._cookie.delete('access_token');
    window.location.href = "/login";
  }

  me() {
    return this._http.get(`${this.baseUrl}/me`);
  }

  create(user) {
    return this._http.post(this.baseUrl, user);
  }

  update(user) {
    if (user.tipo == "ESTUDANTE") {
      return this._http.put(this.baseEstudante, user);
    } else if (user.tipo == "REPUBLICA") {
      return this._http.put(this.baseRepublica, user);
    }
    return this._http.put(this.baseUrl, user);
  }

}
