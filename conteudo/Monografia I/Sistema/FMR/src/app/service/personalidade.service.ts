import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';

@Injectable({
  providedIn: 'root'
})
export class PersonalidadeService {

  constructor(private _http : HttpClient) { }

  private base_url : string = "http://localhost:8080/personalidade";

  getPersonalidade() {
    return this._http.get(this.base_url);
  }
}
