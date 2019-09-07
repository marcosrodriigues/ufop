import { Injectable } from '@angular/core';
import { HttpClient, HttpParams } from '@angular/common/http';
import { Router } from '@angular/router';
import { CookieService } from 'ngx-cookie-service';

@Injectable({
  providedIn: 'root'
})
export class UserService {

  constructor(private _router : Router,
              private _http : HttpClient,
              private _cookie : CookieService ) { }

  private baseUrl : string =  "http://localhost:8080/user";
  private baseEstudante : string =  "http://localhost:8080/estudante";
  private baseRepublica : string =  "http://localhost:8080/republica";

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

    return this._http.post('http://localhost:8080/' + 'oauth/token', params, {headers});
  }

  delete() {
    return this._http.delete(this.baseUrl);
  }

  saveToken(token) {
    var expiredDate = new Date().getTime() + (token.expires_in);
    this._cookie.set('access_token', token.access_token, expiredDate);
  }

  checkCredentials() {
    if (!this._cookie.check('access_token'))
      this._router.navigate(['/login']);
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
