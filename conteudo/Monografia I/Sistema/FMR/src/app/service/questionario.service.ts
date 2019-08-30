import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';

@Injectable({
  providedIn: 'root'
})
export class QuestionarioService {

  constructor(private _http : HttpClient) { }

  private baseUrl: string = "http://localhost:8080/pergunta";

  getAll() {
    return this._http.get(this.baseUrl);
  }
}
