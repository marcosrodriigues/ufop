import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';

@Injectable({
  providedIn: 'root'
})
export class UniversidadeService {

  private baseUrl: string = "http://localhost:8080/universidade";

  constructor(private _http : HttpClient) { }

  getAll() {
    return this._http.get(this.baseUrl);
  }

  save(universidade) {
    return this._http.post(this.baseUrl, universidade);
  }


}
