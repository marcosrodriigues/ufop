import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';

@Injectable({
  providedIn: 'root'
})
export class UserService {

  constructor(private http : HttpClient) { }
  baseUrl : string =  "http://localhost:8080/user";

  login(loginPayload) {
    const headers = {
      'Authorization': 'Basic ' + btoa('frm-client:frm-secret'),
      'Content-type': 'application/x-www-form-urlencoded'
    }
    
    return this.http.post('http://localhost:8080/' + 'oauth/token', loginPayload, {headers});
  }

  getUsers() {
    return this.http.get(
      this.baseUrl + 'user?access_token=' + JSON.parse(window.sessionStorage.getItem('token')).access_token);
  }

  getUserById(id: number) {
    return this.http.get(this.baseUrl + 'user/' + id + '?access_token=' + JSON.parse(window.sessionStorage.getItem('token')).access_token);
  }

  create(user) {
    return this.http.post(this.baseUrl, user);
  }

  updateUser(user) {
    return this.http.put(this.baseUrl + 'user/' + user.id + '?access_token=' + JSON.parse(window.sessionStorage.getItem('token')).access_token, user);
  }

  deleteUser(id: number){
    return this.http.delete(this.baseUrl + 'user/' + id + '?access_token=' + JSON.parse(window.sessionStorage.getItem('token')).access_token);
  }
}
